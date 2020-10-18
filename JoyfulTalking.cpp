#include <bangtal>
using namespace bangtal;

int main()
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, true);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	ScenePtr scene = Scene::create("방", "Images/방.png");

	// 시작 및 종료 버튼, 아기, 말풍선과 지시어 등 기본 환경 설정
	auto ObjectX = 700, ObjectY = 440;
	ObjectPtr bubble = Object::create("Images/말풍선.png", scene, ObjectX-100, ObjectY-140, false);
	bubble->setScale(0.4f);

	ObjectPtr chicken = Object::create("Images/치킨.png", scene, ObjectX, ObjectY, false);
	chicken->setScale(0.2f);
	ObjectPtr chicken_p = Object::create("Images/치킨.png", scene, ObjectX+1000, ObjectY, false);
	chicken_p->setScale(0.2f);

	ObjectPtr dog = Object::create("Images/강아지.png", scene, ObjectX, ObjectY, false);
	dog->setScale(0.2f);
	ObjectPtr dog_p = Object::create("Images/강아지.png", scene, ObjectX + 1000, ObjectY + 1000, false);
	dog_p->setScale(0.2f);

	ObjectPtr rice = Object::create("Images/밥.png", scene, ObjectX, ObjectY, false);
	rice->setScale(0.2f);
	ObjectPtr rice_p = Object::create("Images/밥.png", scene, ObjectX + 1000, ObjectY + 1000, false);
	rice_p->setScale(0.2f);

	ObjectPtr love = Object::create("Images/사랑.png", scene, ObjectX, ObjectY, false);
	love->setScale(0.2f);
	ObjectPtr love_p = Object::create("Images/사랑.png", scene, ObjectX + 1000, ObjectY + 1000, false);
	love_p->setScale(0.2f);

	ObjectPtr spoon = Object::create("Images/숟가락.png", scene, ObjectX, ObjectY, false);
	spoon->setScale(0.2f);
	ObjectPtr spoon_p = Object::create("Images/숟가락.png", scene, ObjectX + 1000, ObjectY + 1000, false);
	spoon_p->setScale(0.2f);

	auto problem = chicken;
	auto answer = chicken;

	ObjectPtr baby = Object::create("Images/아기.png", scene, 370, 140);

	auto startButton = Object::create("Images/start.png", scene, 590, 70);
	auto endButton = Object::create("Images/end.png", scene, 590, 20);


	//게임 시작 버튼을 누르면 지시어가 뜨고 타이머가 실행된다.
	auto timer1 = Timer::create(10.f);
	auto timer2 = Timer::create(4.f);
	auto timer3 = Timer::create(4.f);
	auto timer4 = Timer::create(4.f);
	auto timer5 = Timer::create(4.f);
	showTimer(timer2);

	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		startButton->hide();
		endButton->hide();
		bubble->show();
		chicken->show();
		chicken_p->pick();

		showMessage("'치킨'이라고 말해보자! *알맞은 그림이 뜰 때 아기를 클릭하세요");
		answer = chicken;

		timer1->start();

		return true;
		});

	timer1->setOnTimerCallback([&](TimerPtr) -> bool {
		chicken->hide();
		dog->show();

		chicken_p->drop();
		dog_p->pick();

		answer = dog;

		timer2->start();

		return true;
		});

	timer2->setOnTimerCallback([&](TimerPtr) -> bool {
		dog->hide();
		rice->show();

		dog_p->drop();
		rice_p->pick();

		answer = rice;

		timer3->start();

		return true;
		});

	timer3->setOnTimerCallback([&](TimerPtr) -> bool {
		rice->hide();
		love->show();

		rice_p->drop();
		love_p->pick();

		answer = love;

		timer4->start();

		return true;
		});
	
	timer4->setOnTimerCallback([&](TimerPtr) -> bool {
		love->hide();
		spoon->show();

		love_p->drop();
		spoon_p->pick();

		answer = spoon;

		timer5->start();

		return true;
		});

	timer5->setOnTimerCallback([&](TimerPtr) -> bool {
		spoon->hide();
		chicken->show();

		spoon_p->drop();
		chicken_p->pick();

		answer = chicken;

		timer1->start();

		return true;
		});


	baby->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (problem == answer) {
			showMessage("성공! 이번엔 '강아지'라고 말해보자!");

		}
		else {
			showMessage("실패! 이번엔 '강아지'라고 말해보자!");

		}

		return true;
		});
		
	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

		return true;
		});

	startGame(scene);


	return 0;
}